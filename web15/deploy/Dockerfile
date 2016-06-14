From linode/lamp:latest
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install php5-mysql

RUN rm -rfd /var/www/example.com
RUN rm /etc/apache2/sites-enabled/example.com.conf
RUN rm /etc/apache2/sites-available/example.com.conf
RUN rm /var/www/html/index.html

RUN echo "NameVirtualHost *:80\r\n<VirtualHost *:80>\r\nServerName potat\r\nDocumentRoot /var/www/html\r\n</VirtualHost>" > /etc/apache2/sites-enabled/000-default.conf

ADD ./src /var/www/html
COPY start.sh start.sh
RUN chmod +x start.sh

ENTRYPOINT ["./start.sh"]

EXPOSE 80