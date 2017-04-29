Copy bolt.service into /etc/systemd/system/bolt.service

sudo cp /home/dash/dash/os/bolt.service /etc/systemd/system/bolt.service

To enable the service at startup, which will execut all of the commands as dash user run:
sudo systemctl reset bolt.service
or
sudo systemctl enable bolt.service
sudo systemctl start bolt.service