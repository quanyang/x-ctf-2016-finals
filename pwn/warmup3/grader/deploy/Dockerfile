FROM ubuntu:latest
RUN apt-get update
RUN apt-get install -y xinetd
RUN apt-get install -y python3
RUN apt-get install -y libc6-i386
RUN useradd -m ping
COPY ./ping.py /home/ping/ping.py
RUN chmod +x /home/ping/ping.py
COPY ./flag /home/ping/flag
COPY ./pingservice /etc/xinetd.d/pingservice
RUN chown -R root:ping /home/ping
RUN chmod -R 750 /home/ping
RUN chown root:ping /home/ping/flag
RUN chmod 440 /home/ping/flag
EXPOSE 31337
CMD ["/usr/sbin/xinetd", "-d"]
