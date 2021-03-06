find . -type f -o -type d | wc -l | tr -s " " | sed 's/ //g'
