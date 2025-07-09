import { useNavigate } from "react-router-dom";
import Profile from "../components/Profile";
import "./Home.css";

function Home() {
  const navigate = useNavigate();

  const handleClick = () => {
    navigate("/game");
  };

  const handleScoreboardClick = () => {
    navigate("/scoreboard");
  };

  return (
    <>
      <Profile />
      <div className="center-container">
        <h1>JägerSweeper</h1>
        <div className="button-container">
          <button onClick={handleClick} className="play-button">Play !</button>
          <button onClick={handleScoreboardClick} className="scoreboard-button">
            🏆 Scoreboard
          </button>
        </div>
      </div>
    </>
  );
}

export default Home;
