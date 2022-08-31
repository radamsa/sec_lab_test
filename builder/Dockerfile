FROM gcc:7
WORKDIR /source
COPY . .
RUN \
    make build
CMD ["make", "test"]
