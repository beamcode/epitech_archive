FROM jenkins/jenkins:lts

COPY plugins.txt /usr/share/jenkins/ref/plugins.txt
COPY my_marvin.yml /home/my_marvin.yml

RUN jenkins-plugin-cli -f /usr/share/jenkins/ref/plugins.txt