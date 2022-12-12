FROM node:16

WORKDIR /app

EXPOSE 1337

COPY package.json .

RUN npm install

COPY . .

CMD ["npm", "run", "dev"]
