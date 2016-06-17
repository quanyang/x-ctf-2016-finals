FROM ubuntu:latest
RUN sed -i 's/archive.ubuntu.com/download.nus.edu.sg\/mirror/g' /etc/apt/sources.list
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y openssh-server
RUN mkdir /var/run/sshd
RUN echo 'root:thishasnopassword' | chpasswd
RUN sed -i 's/PermitRootLogin without-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

RUN useradd -m cattee
RUN echo cattee:cattee | chpasswd

RUN mkdir /home/cattee/bin/
RUN cp `which cat` /home/cattee/bin/cat
RUN cp `which tee` /home/cattee/bin/tee
RUN cp `which ls` /home/cattee/bin/ls

COPY ./restrict_bash.sh /home/cattee/restrict_bash.sh

RUN chown -R root:cattee /home/cattee
RUN chmod -R 750 /home/cattee

RUN mkdir /home/cattee/sbin/
COPY ./get_flag /home/cattee/sbin/get_flag
COPY ./flag /home/cattee/sbin/flag

RUN chown -R root:cattee /home/cattee/sbin
RUN chmod -R 750 /home/cattee/sbin/
RUN chmod 400 /home/cattee/sbin/flag
RUN chmod +s /home/cattee/sbin/get_flag

RUN chsh -s /home/cattee/restrict_bash.sh cattee

RUN chmod 1733 /tmp /var/tmp /dev/shm

EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
