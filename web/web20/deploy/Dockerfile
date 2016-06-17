From linode/lamp:latest
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install php5-mysql php5-curl

RUN rm -rfd /var/www/example.com
RUN rm /etc/apache2/sites-enabled/example.com.conf
RUN rm /etc/apache2/sites-available/example.com.conf
RUN rm /var/www/html/index.html

RUN echo "NameVirtualHost *:80\r\n<VirtualHost *:80>\r\nServerName potat\r\nDocumentRoot /var/www/html\r\n</VirtualHost>" > /etc/apache2/sites-enabled/000-default.conf

ADD ./src /var/www/html
COPY start.sh start.sh
RUN mv /var/www/html/flag_is_here.lol /flag_is_here.lol
RUN chmod 444 /flag_is_here.lol
RUN mkdir /var/www/html/hitimages
RUN chown www-data:www-data -R /var/www/html/hitimages
RUN chmod +x start.sh
RUN chmod +w /var/www/html/hitimages

ENTRYPOINT ["./start.sh"]

EXPOSE 80
