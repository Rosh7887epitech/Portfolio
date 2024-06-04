FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y nodejs npm

WORKDIR /app

COPY . /app

RUN npm install

EXPOSE 3000

CMD ["node", "app.js"]
