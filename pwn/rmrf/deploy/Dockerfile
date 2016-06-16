FROM ubuntu:latest
RUN apt-get update
RUN apt-get upgrade
RUN apt-get install -y openssh-server
RUN mkdir /var/run/sshd
RUN echo 'root:screencast' | chpasswd
RUN sed -i 's/PermitRootLogin without-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

RUN useradd -m rmrf
RUN echo rmrf:rmrf | chpasswd
RUN echo IyEvYmluL2Jhc2gKY2hyb290IC0tdXNlcnNwZWM9MTAwMCAvbm90aGluZyAvYmluL3NoCg== | base64 -d > /bin/chrsh
RUN chmod +x /bin/chrsh
RUN chsh -s /bin/chrsh rmrf
RUN chmod +s `which chroot`

RUN mkdir /nothing
RUN mkdir /nothing/{bin,dev,proc,lib}
RUN mount --bind /dev/ /nothing/dev/
RUN mount --bind /proc/ /nothing/proc/
RUN cp /bin/sh /nothing/bin/sh
RUN /mkdir /nothing/lib/x86_64-linux-gnu/
RUN cp /lib/x86_64-linux-gnu/libtinfo.so.5 /nothing/lib/x86_64-linux-gnu/libtinfo.so.5
RUN cp /lib/x86_64-linux-gnu/libdl.so.2 /nothing/lib/x86_64-linux-gnu/libdl.so.2
RUN cp /lib/x86_64-linux-gnu/libc.so.6 /nothing//lib/x86_64-linux-gnu/libc.so.6
RUN mkdir lib64
RUN cp /lib64/ld-linux-x86-64.so.2 /nothing/lib64/ld-linux-x86-64.so.2

RUN mkdir /nothing/dev/treasure/
RUN echo "XCTF{DANKMEMESCANTMELTSTEELBEAMS}" > /dev/treasure/fl_ag_come_at_me_bro

EXPOSE 8001
CMD ["/usr/sbin/sshd", "-D"]
