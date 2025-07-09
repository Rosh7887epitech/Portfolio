import 'leaflet/dist/leaflet.css';
import L from 'leaflet';
import { createMap } from './js_funct/map.js';
import { fetchAndDisplayParkings } from './js_funct/parking.js';
import { fetchAndDisplayBikesPark } from './js_funct/bike_park.js';

const map = createMap();
const markersLayerParkings = L.layerGroup().addTo(map);
const markersLayerBikeParkings = L.layerGroup().addTo(map);

fetchAndDisplayParkings(map, markersLayerParkings);
fetchAndDisplayBikesPark(map, markersLayerBikeParkings)

setInterval(() => {
  if (document.querySelector('#toggle-parkings').checked) {
    fetchAndDisplayParkings(map, markersLayerParkings);
  }
  if (document.querySelector('#toggle-bikeparkings').checked) {
    fetchAndDisplayBikesPark(map, markersLayerBikeParkings);
  }
}, 120000);

document.querySelector('#toggle-parkings').addEventListener('change', (e) => {
  if (e.target.checked) {
    map.addLayer(markersLayerParkings);
    fetchAndDisplayParkings(map, markersLayerParkings);
  } else {
    map.removeLayer(markersLayerParkings);
  }
});

document.querySelector('#toggle-bikeparkings').addEventListener('change', (e) => {
  if (e.target.checked) {
    map.addLayer(markersLayerBikeParkings);
    fetchAndDisplayBikesPark(map, markersLayerBikeParkings);
  } else {
    map.removeLayer(markersLayerBikeParkings);
  }
});
