#!/bin/bash
#Description: 自动化FTP 传输
#
#Author: XYJ
#Version:1.0
#CreateTime:'20181013--06:42'

HOST='domain.com'
USER='foo'
PASSWD='password'
ftp -i -n $HOST <<EOF
user ${USER} ${PASSWD}
binary

cd /home/slynux
puttestfile.jpg
getserverfile.jpg
quit
EOF

