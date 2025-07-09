import { park_greenIcon, park_orangeIcon, park_redIcon } from './icons.js';

function getParkingIcon(ratio) {
  if (ratio < 0.5) return park_greenIcon;
  if (ratio < 0.8) return park_orangeIcon;
  return park_redIcon;
}

export function fetchAndDisplayParkings(map, markersLayer) {
  const apiUrl = "https://data.nantesmetropole.fr/api/explore/v2.1/catalog/datasets/244400404_parkings-publics-nantes-disponibilites/records?limit=30";

  fetch(apiUrl)
    .then(res => res.json())
    .then(data => {
      console.log('Données API parking :', data);
      markersLayer.clearLayers();

      data.results.forEach(parking => {
        const { grp_nom, grp_disponible, grp_exploitation, adresse, location } = parking;
        if (!location?.lat || !location?.lon) return;

        const icon = getParkingIcon(grp_disponible / grp_exploitation);
        const lat = location.lat;
        const lon = location.lon;

        L.marker([lat, lon], { icon })
          .addTo(markersLayer)
          .bindPopup(`
            <strong>${grp_nom}</strong><br>
            📍 ${adresse}<br>
            🅿️ ${grp_disponible} / ${grp_exploitation} places dispo
          `);
      });
    })
    .catch(err => console.error("Erreur de chargement des parkings :", err));
}
