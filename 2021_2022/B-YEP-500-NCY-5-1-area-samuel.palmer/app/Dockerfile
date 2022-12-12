FROM node:16

WORKDIR /app

COPY package.json .

RUN npm install && npm install --global expo-cli

COPY . .

CMD ["expo", "start"]
