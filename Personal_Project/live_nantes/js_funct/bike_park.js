import { bike_greenIcon, bike_orangeIcon, bike_redIcon } from './icons.js';

function getBikeParkIcon(ratio) {
  if (ratio < 0.5) return bike_greenIcon;
  if (ratio < 0.8) return bike_orangeIcon;
  return bike_redIcon;
}

export function fetchAndDisplayBikesPark(map, markersLayer) {
  const apiUrl = 'https://data.nantesmetropole.fr/api/explore/v2.1/catalog/datasets/244400404_disponibilite-temps-reel-velos-libre-service-naolib-nantes-metropole/records?limit=100';

  fetch(apiUrl)
    .then(res => res.json())
    .then(data => {
      console.log('Données API vélo :', data);
      markersLayer.clearLayers();

      data.results.forEach(station => {
        const { position, name, address, available_bikes, available_bike_stands, bike_stands, rental_methods } = station;
        if (!position?.lat || !position?.lon) return;

        const icon = getBikeParkIcon(available_bikes / bike_stands);

        L.marker([position.lat, position.lon], { icon })
          .addTo(markersLayer)
          .bindPopup(`
          <strong>${name}</strong><br>
          📍 ${address}<br>
          🚲 Vélos disponibles : ${available_bikes} / ${bike_stands}<br>
          🅿️ Emplacements libres : ${available_bike_stands}<br>
          💳 Paiement CB : ${rental_methods ? '✅' : '❌'}<br>
        `);
      });
    });
}
