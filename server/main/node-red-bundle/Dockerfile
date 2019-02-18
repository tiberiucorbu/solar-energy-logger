FROM node:alpine
WORKDIR /tciot/node-red-bundle

COPY package.json package-lock.json settings.js ./

RUN npm ci

EXPOSE 1880

CMD npm start