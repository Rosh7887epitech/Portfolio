import { useState, useRef, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import settingIcon from '../assets/setting.svg';
import pauseIcon from '../assets/pause-button.svg';

function Game() {
    const navigate = useNavigate();
    const [position, setPosition] = useState({ x: 0, y: 0 });
    const [isDragging, setIsDragging] = useState(false);
    const [startPosition, setStartPosition] = useState({ x: 0, y: 0 });
    const [viewportDimensions, setViewportDimensions] = useState({ width: 0, height: 0 });
    const [zoom, setZoom] = useState(1);
    const [revealedCells, setRevealedCells] = useState(new Set());
    const [flaggedCells, setFlaggedCells] = useState(new Set());
    const [score, setScore] = useState(0);
    const [dragStart, setDragStart] = useState({ x: 0, y: 0, time: 0 });
    const [isPaused, setIsPaused] = useState(false);
    const [showPauseMenu, setShowPauseMenu] = useState(false);
    const [gridData, setGridData] = useState(new Map());
    const [initializedChunks, setInitializedChunks] = useState(new Set());
    const [gameOver, setGameOver] = useState(false);
    const [showGameOverMenu, setShowGameOverMenu] = useState(false);
    const [timeLeft, setTimeLeft] = useState(300);
    const gridRef = useRef(null);
    const BASE_CELL_SIZE = 50;
    const CHUNK_SIZE = 30;

    useEffect(() => {
        const updateViewportDimensions = () => {
            setViewportDimensions({
                width: window.innerWidth,
                height: window.innerHeight
            });
        };
        updateViewportDimensions();
        window.addEventListener('resize', updateViewportDimensions);

        let timer;
        if (!isPaused && !gameOver) {
            timer = setInterval(() => {
                setTimeLeft(prev => {
                    if (prev <= 1) {
                        clearInterval(timer);
                        setGameOver(true);
                        setShowGameOverMenu(true);
                        saveScore(score); // Sauvegarder le score quand le temps se termine
                        return 0;
                    }
                    return prev - 1;
                });
            }, 1000);
        }

        return () => {
            window.removeEventListener('resize', updateViewportDimensions);
            clearInterval(timer);
        };
    }, [isPaused, gameOver]);

    useEffect(() => {
        const handleBeforeUnload = (event) => {
            if (score > 0 && !gameOver) {
                // Sauvegarder le score avant de quitter
                saveScore(score);
            }
        };

        const handlePopState = () => {
            if (score > 0 && !gameOver) {
                saveScore(score);
            }
        };

        window.addEventListener('beforeunload', handleBeforeUnload);
        window.addEventListener('popstate', handlePopState);

        return () => {
            window.removeEventListener('beforeunload', handleBeforeUnload);
            window.removeEventListener('popstate', handlePopState);
            // Sauvegarder le score lors du démontage du composant
            if (score > 0 && !gameOver) {
                saveScore(score);
            }
        };
    }, [score, gameOver]);

    const getChunkKey = (x, y) => {
        const cx = Math.floor(x / CHUNK_SIZE);
        const cy = Math.floor(y / CHUNK_SIZE);
        return `${cx},${cy}`;
    };

    const generateChunk = (cx, cy, safeX = null, safeY = null) => {
        const newGrid = new Map(gridData);
        const newChunks = new Set(initializedChunks);
        const startX = cx * CHUNK_SIZE;
        const startY = cy * CHUNK_SIZE;
        const endX = startX + CHUNK_SIZE;
        const endY = startY + CHUNK_SIZE;

        const getKey = (x, y) => `${x},${y}`;
        const isSafeZone = (x, y) => safeX !== null && safeY !== null && Math.abs(x - safeX) <= 2 && Math.abs(y - safeY) <= 2;

        const bombCount = 185;
        const bombPositions = new Set();
        while (bombPositions.size < bombCount) {
            const x = Math.floor(Math.random() * CHUNK_SIZE) + startX;
            const y = Math.floor(Math.random() * CHUNK_SIZE) + startY;
            if (isSafeZone(x, y)) continue;
            bombPositions.add(getKey(x, y));
        }

        for (let y = startY; y < endY; y++) {
            for (let x = startX; x < endX; x++) {
                const key = getKey(x, y);
                const isBomb = bombPositions.has(key);
                newGrid.set(key, {
                    x,
                    y,
                    isBomb,
                    count: 0,
                });
            }
        }

        for (const key of bombPositions) {
            const [x, y] = key.split(',').map(Number);
            for (let dy = -1; dy <= 1; dy++) {
                for (let dx = -1; dx <= 1; dx++) {
                    if (dx === 0 && dy === 0) continue;
                    const nKey = getKey(x + dx, y + dy);
                    if (newGrid.has(nKey) && !newGrid.get(nKey).isBomb) {
                        newGrid.get(nKey).count++;
                    }
                }
            }
        }

        newChunks.add(`${cx},${cy}`);
        setGridData(newGrid);
        setInitializedChunks(newChunks);
    };

    const getVisibleGridArea = () => {
        const extraCells = 4;
        const cellSize = BASE_CELL_SIZE * zoom;
        const startX = Math.floor(-position.x / cellSize) - extraCells;
        const startY = Math.floor(-position.y / cellSize) - extraCells;
        const endX = Math.ceil((viewportDimensions.width - position.x) / cellSize) + extraCells;
        const endY = Math.ceil((viewportDimensions.height - position.y) / cellSize) + extraCells;
        return { startX, startY, endX, endY };
    };

    const revealCell = (x, y, visited = new Set()) => {
        const key = `${x},${y}`;
        if (!gridData.has(key) || visited.has(key) || flaggedCells.has(key)) return;
        visited.add(key);

        const cell = gridData.get(key);
        setRevealedCells(prev => {
            const newSet = new Set(prev);
            if (!newSet.has(key)) {
                newSet.add(key);
                setScore(prevScore => prevScore + 1);
            }
            return newSet;
        });

        if (cell.count === 0 && !cell.isBomb) {
            for (let dx = -1; dx <= 1; dx++) {
                for (let dy = -1; dy <= 1; dy++) {
                    if (dx === 0 && dy === 0) continue;
                    revealCell(x + dx, y + dy, visited);
                }
            }
        }
    };

    const handleCellClick = (x, y) => {
        const chunkKey = getChunkKey(x, y);
        if (!initializedChunks.has(chunkKey)) {
            generateChunk(Math.floor(x / CHUNK_SIZE), Math.floor(y / CHUNK_SIZE), x, y);
        }

        const key = `${x},${y}`;
        const cell = gridData.get(key);
        if (isPaused || gameOver || !cell || revealedCells.has(key) || flaggedCells.has(key)) return;

        if (cell.isBomb) {
            setGameOver(true);
            setShowGameOverMenu(true);
            setRevealedCells(prev => {
                const newSet = new Set(prev);
                if (!newSet.has(key)) {
                    newSet.add(key);
                    const finalScore = score + 1;
                    setScore(finalScore);
                    saveScore(finalScore); // Sauvegarder le score final
                }
                return newSet;
            });
            return;
        }

        revealCell(x, y, new Set());
    };

    const handleCellRightClick = (e, x, y) => {
        e.preventDefault();
        const key = `${x},${y}`;
        if (isPaused || gameOver || revealedCells.has(key)) return;
        setFlaggedCells(prev => {
            const newSet = new Set(prev);
            if (newSet.has(key)) {
                newSet.delete(key);
            } else {
                newSet.add(key);
            }
            return newSet;
        });
    };

    const handlePauseClick = () => {
        setIsPaused(true);
        setShowPauseMenu(true);
    };

    const handleResume = () => {
        setIsPaused(false);
        setShowPauseMenu(false);
    };

    const handleQuit = () => {
        // Sauvegarder le score actuel avant de quitter
        if (score > 0) {
            saveScore(score);
        }
        navigate('/');
    };

    const saveScore = async (finalScore) => {
        const token = localStorage.getItem('token');
        if (!token) return; // Pas connecté, pas de sauvegarde

        try {
            await fetch('http://localhost:5000/api/scores', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Authorization': `Bearer ${token}`
                },
                body: JSON.stringify({ score: finalScore }),
                keepalive: true // Permet à la requête de continuer même si la page se ferme
            });
        } catch (error) {
            console.error('Erreur lors de la sauvegarde du score:', error);
        }
    };

    const handleRestart = () => {
        setPosition({ x: 0, y: 0 });
        setRevealedCells(new Set());
        setFlaggedCells(new Set());
        setScore(0);
        setGridData(new Map());
        setInitializedChunks(new Set());
        setGameOver(false);
        setShowGameOverMenu(false);
        setTimeLeft(300);
        setIsPaused(false);
        setShowPauseMenu(false);
    };

    const renderGrid = () => {
        const { startX, startY, endX, endY } = getVisibleGridArea();
        const cells = [];
        const CELL_SIZE = BASE_CELL_SIZE;

        for (let y = startY; y <= endY; y++) {
            for (let x = startX; x <= endX; x++) {
                const key = `${x},${y}`;
                const cell = gridData.get(key);
                const revealed = revealedCells.has(key);
                const flagged = flaggedCells.has(key);
                let label = '';

                if (revealed) {
                    label = cell?.isBomb && gameOver ? '💣' : (cell?.count > 0 ? cell.count : '');
                } else if (flagged) {
                    label = '🚩';
                }

                cells.push(
                    <div
                        key={key}
                        onClick={() => handleCellClick(x, y)}
                        onContextMenu={(e) => handleCellRightClick(e, x, y)}
                        style={{
                            position: 'absolute',
                            left: x * CELL_SIZE + 'px',
                            top: y * CELL_SIZE + 'px',
                            width: CELL_SIZE + 'px',
                            height: CELL_SIZE + 'px',
                            border: '1px solid #ccc',
                            boxSizing: 'border-box',
                            backgroundColor: revealed ? '#ddd' : '#aaa',
                            transition: 'background-color 0.2s',
                            display: 'flex',
                            alignItems: 'center',
                            justifyContent: 'center',
                            fontWeight: 'bold',
                            color: cell?.isBomb ? 'black' : 'blue',
                            userSelect: 'none',
                            cursor: 'pointer'
                        }}
                    >
                        {label}
                    </div>
                );
            }
        }
        return cells;
    };

    const handleMouseDown = (e) => {
        setIsDragging(true);
        setDragStart({ x: e.clientX, y: e.clientY, time: Date.now() });
        setStartPosition({
            x: e.clientX - position.x,
            y: e.clientY - position.y
        });
    };

    const handleMouseMove = (e) => {
        if (!isDragging) return;
        setPosition({
            x: e.clientX - startPosition.x,
            y: e.clientY - startPosition.y
        });
    };

    const handleMouseUp = () => {
        setIsDragging(false);
    };

    const handleWheel = (e) => {
        e.preventDefault();
        const zoomSpeed = 0.1;
        const delta = e.deltaY > 0 ? -zoomSpeed : zoomSpeed;
        const newZoom = Math.max(0.2, Math.min(5, zoom + delta));
        const rect = e.currentTarget.getBoundingClientRect();
        const mouseX = e.clientX - rect.left;
        const mouseY = e.clientY - rect.top;
        const scaleDiff = newZoom - zoom;
        setPosition({
            x: position.x - (mouseX - position.x) * (scaleDiff / zoom),
            y: position.y - (mouseY - position.y) * (scaleDiff / zoom)
        });
        setZoom(newZoom);
    };

    return (
        <>
            {showPauseMenu && (
                <div style={{
                    position: 'fixed',
                    top: 0,
                    left: 0,
                    width: '100vw',
                    height: '100vh',
                    backgroundColor: 'rgba(0, 0, 0, 0.7)',
                    zIndex: 10000,
                    display: 'flex',
                    alignItems: 'center',
                    justifyContent: 'center'
                }}>
                    <div style={{
                        backgroundColor: 'white',
                        padding: '40px',
                        borderRadius: '12px',
                        boxShadow: '0 10px 30px rgba(0, 0, 0, 0.5)',
                        textAlign: 'center',
                        minWidth: '300px'
                    }}>
                        <h2 style={{ margin: '0 0 30px 0', color: '#333' }}>Jeu en pause</h2>
                        <div style={{ display: 'flex', flexDirection: 'column', gap: '15px' }}>
                            <button
                                onClick={handleResume}
                                style={{
                                    padding: '12px 24px',
                                    backgroundColor: '#28a745',
                                    color: 'white',
                                    border: 'none',
                                    borderRadius: '6px',
                                    fontSize: '16px',
                                    cursor: 'pointer',
                                    transition: 'background-color 0.2s'
                                }}
                                onMouseOver={(e) => e.target.style.backgroundColor = '#218838'}
                                onMouseOut={(e) => e.target.style.backgroundColor = '#28a745'}
                            >
                                Reprendre
                            </button>
                            <button
                                onClick={handleQuit}
                                style={{
                                    padding: '12px 24px',
                                    backgroundColor: '#dc3545',
                                    color: 'white',
                                    border: 'none',
                                    borderRadius: '6px',
                                    fontSize: '16px',
                                    cursor: 'pointer',
                                    transition: 'background-color 0.2s'
                                }}
                                onMouseOver={(e) => e.target.style.backgroundColor = '#c82333'}
                                onMouseOut={(e) => e.target.style.backgroundColor = '#dc3545'}
                            >
                                Quitter
                            </button>
                        </div>
                    </div>
                </div>
            )}

            {/* Game Over Menu */}
            {showGameOverMenu && (
                <div style={{
                    position: 'fixed',
                    top: 0,
                    left: 0,
                    width: '100vw',
                    height: '100vh',
                    backgroundColor: 'rgba(0, 0, 0, 0.8)',
                    zIndex: 10000,
                    display: 'flex',
                    alignItems: 'center',
                    justifyContent: 'center'
                }}>
                    <div style={{
                        backgroundColor: 'white',
                        padding: '40px',
                        borderRadius: '12px',
                        boxShadow: '0 10px 30px rgba(0, 0, 0, 0.5)',
                        textAlign: 'center',
                        minWidth: '350px'
                    }}>
                        <h2 style={{ 
                            margin: '0 0 20px 0', 
                            color: '#dc3545',
                            fontSize: '32px',
                            fontWeight: 'bold'
                        }}>
                            💥 GAME OVER 💥
                        </h2>
                        <p style={{
                            margin: '0 0 30px 0',
                            color: '#666',
                            fontSize: '18px'
                        }}>
                            Vous avez touché une mine !<br/>
                            <strong style={{ color: '#333' }}>Score final : {score} points</strong>
                        </p>
                        <div style={{ display: 'flex', flexDirection: 'column', gap: '15px' }}>
                            <button
                                onClick={handleRestart}
                                style={{
                                    padding: '12px 24px',
                                    backgroundColor: '#28a745',
                                    color: 'white',
                                    border: 'none',
                                    borderRadius: '6px',
                                    fontSize: '16px',
                                    cursor: 'pointer',
                                    transition: 'background-color 0.2s',
                                    fontWeight: 'bold'
                                }}
                                onMouseOver={(e) => e.target.style.backgroundColor = '#218838'}
                                onMouseOut={(e) => e.target.style.backgroundColor = '#28a745'}
                            >
                                🔄 Rejouer
                            </button>
                            <button
                                onClick={handleQuit}
                                style={{
                                    padding: '12px 24px',
                                    backgroundColor: '#6c757d',
                                    color: 'white',
                                    border: 'none',
                                    borderRadius: '6px',
                                    fontSize: '16px',
                                    cursor: 'pointer',
                                    transition: 'background-color 0.2s',
                                    fontWeight: 'bold'
                                }}
                                onMouseOver={(e) => e.target.style.backgroundColor = '#5a6268'}
                                onMouseOut={(e) => e.target.style.backgroundColor = '#6c757d'}
                            >
                                🏠 Quitter
                            </button>
                        </div>
                    </div>
                </div>
            )}
            
            <button
                onClick={handlePauseClick}
                style={{
                    position: 'fixed',
                    top: '10px',
                    left: '50%',
                    transform: 'translateX(-50%)',
                    zIndex: 1000,
                    padding: '6px 12px',
                    backgroundColor: '#007bff',
                    color: 'white',
                    border: 'none',
                    borderRadius: '4px',
                    cursor: 'pointer'
                }}
            >
                Pause
            </button>

            <div style={{
                position: 'fixed',
                top: '10px',
                right: '10px',
                padding: '8px 12px',
                backgroundColor: 'white',
                color: 'black',
                border: '1px solid #ccc',
                borderRadius: '6px',
                boxShadow: '0 2px 5px rgba(0,0,0,0.1)',
                fontSize: '16px',
                fontWeight: 'bold',
                zIndex: 999
            }}>
                ⏱ {Math.floor(timeLeft / 60)}:{(timeLeft % 60).toString().padStart(2, '0')}
            </div>

            <div style={{
                position: 'fixed',
                top: '10px',
                left: '10px',
                padding: '8px 12px',
                backgroundColor: 'white',
                color: 'black',
                border: '1px solid #ccc',
                borderRadius: '6px',
                boxShadow: '0 2px 5px rgba(0,0,0,0.1)',
                fontSize: '16px',
                fontWeight: 'bold',
                zIndex: 999
            }}>
                🚩 {flaggedCells.size}
            </div>

            <div style={{
                position: 'fixed',
                top: '60px',
                left: '10px',
                padding: '8px 12px',
                backgroundColor: 'white',
                color: 'black',
                border: '1px solid #ccc',
                borderRadius: '6px',
                boxShadow: '0 2px 5px rgba(0,0,0,0.1)',
                fontSize: '16px',
                fontWeight: 'bold',
                zIndex: 999
            }}>
                🏆 {score}
            </div>

            <div
                className="game-container"
                onMouseDown={handleMouseDown}
                onMouseMove={handleMouseMove}
                onMouseUp={handleMouseUp}
                onMouseLeave={handleMouseUp}
                onWheel={handleWheel}
                style={{
                    width: '100vw',
                    height: '100vh',
                    overflow: 'hidden',
                    position: 'relative',
                    backgroundColor: '#f0f0f0',
                    cursor: isDragging ? 'grabbing' : 'grab'
                }}
            >
                <div
                    ref={gridRef}
                    style={{
                        position: 'absolute',
                        transform: `translate(${position.x}px, ${position.y}px) scale(${zoom})`,
                        width: '100%',
                        height: '100%',
                        transformOrigin: '0 0'
                    }}
                >
                    {renderGrid()}
                </div>
            </div>
        </>
    );
}

export default Game;
