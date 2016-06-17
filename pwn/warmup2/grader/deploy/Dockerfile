FROM ubuntu:latest
RUN apt-get update
RUN apt-get install -y xinetd
RUN apt-get install -y libc6-i386
RUN useradd -m formatstr
COPY ./fmt /home/formatstr/fmt
COPY ./password.txt /home/formatstr/password.txt
COPY ./password.txt /password.txt
RUN chown root:formatstr /password.txt
RUN chmod 750 /password.txt
COPY ./flag /home/formatstr/flag
COPY ./fmtservice /etc/xinetd.d/fmtservice
RUN chown -R root:formatstr /home/formatstr
RUN chmod -R 750 /home/formatstr
RUN chown root:formatstr /home/formatstr/flag
RUN chmod 440 /home/formatstr/flag
EXPOSE 31338
CMD ["/usr/sbin/xinetd", "-d"]
