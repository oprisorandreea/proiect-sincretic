FROM gcc:latest
WORKDIR /usr/src/myapp
COPY myapp.c .
RUN gcc -o myapp myapp.c 
EXPOSE 80
CMD ["./myapp"]