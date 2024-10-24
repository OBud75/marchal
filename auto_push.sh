#!/usr/bin/sh

COMMIT_NAME=$1

git add .
git commit -a -m "$COMMIT_NAME"
git push
