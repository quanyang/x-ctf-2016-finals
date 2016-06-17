FROM ubuntu:latest
RUN sed -i 's/archive.ubuntu.com/download.nus.edu.sg\/mirror/g' /etc/apt/sources.list
RUN apt-get update
RUN apt-get install -y xinetd python gcc
RUN useradd -m speedre
COPY ./speedre.py /home/speedre/speedre.py
COPY ./template.c /home/speedre/template.c
COPY ./flag /home/speedre/flag
COPY ./speedreservice /etc/xinetd.d/speedreservice
RUN chown -R root:speedre /home/speedre
RUN chmod -R 750 /home/speedre
RUN chown root:speedre /home/speedre/flag
RUN chmod 440 /home/speedre/flag
EXPOSE 31337
CMD ["/usr/sbin/xinetd", "-d"]
