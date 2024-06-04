FROM maven:3.9.6-eclipse-temurin-21-alpine as builder

WORKDIR /app

COPY . /app/

RUN mvn dependency:resolve

RUN cd src/

RUN mvn package

FROM eclipse-temurin:21-jre-alpine

WORKDIR /app

COPY --from=builder /app/target/worker-jar-with-dependencies.jar /app/worker-jar-with-dependencies.jar

CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]
