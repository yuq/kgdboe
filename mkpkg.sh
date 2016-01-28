#!/bin/bash

. ./dkms.conf

DKMS_DIR="/usr/src/$PACKAGE_NAME-$PACKAGE_VERSION"

sudo mkdir -p $DKMS_DIR
sudo cp -r * $DKMS_DIR
sudo rm $DKMS_DIR/*.deb
sudo dkms add -m $PACKAGE_NAME -v $PACKAGE_VERSION
sudo dkms mkdeb -m $PACKAGE_NAME -v $PACKAGE_VERSION --source-only
cp /var/lib/dkms/$PACKAGE_NAME/$PACKAGE_VERSION/deb/* .
sudo dkms remove -m $PACKAGE_NAME -v $PACKAGE_VERSION --all
sudo rm -rf $DKMS_DIR
