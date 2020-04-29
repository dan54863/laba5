FROM ubuntu
COPY ./la5.cpp .
COPY ./123.txt .
RUN apt update
RUN apt install -y vim
RUN apt install -y build-essential

