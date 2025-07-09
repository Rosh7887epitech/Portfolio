FROM jenkins/jenkins:lts

ENV JAVA_OPTS="-Djenkins.install.runSetupWizard=false"

USER root

RUN apt-get update && apt-get install -y gcc g++ make

USER jenkins

RUN jenkins-plugin-cli --plugins configuration-as-code job-dsl role-strategy ws-cleanup git github

COPY my_marvin.yml /var/jenkins_home/configuration.yml
COPY job_dsl.groovy /var/jenkins_home/job_dsl.groovy

CMD ["/usr/local/bin/jenkins.sh"]
