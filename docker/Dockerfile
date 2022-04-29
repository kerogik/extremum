FROM nginx:mainline

RUN /bin/bash &&\
    apt update &&\
    apt-get install gnuplot -y &&\
    apt install git -y &&\
    apt install mingw-w64 -y &&\
    apt install build-essential -y &&\
    cd ~ &&\
    git clone https://github.com/kerogik/extremum.git &&\
    cd extremum &&\
    g++ -s -I. -std=c++17 -o extremum-compiled main.cpp &&\
    rm -f /root/extremum/extremum &&\
    ln -s -T /root/extremum/extremum-compiled /root/extremum/extremum

COPY ./html/ /usr/share/nginx/html/

COPY ./start_script/ /root/extremum/ 

ENV LC_ALL="en_US.UTF-8"

EXPOSE 8080:80





