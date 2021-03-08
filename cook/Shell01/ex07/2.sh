cat /etc/passwd | sed '/#/d' | cut -d ":" -f 1 | awk 'NR%2==0' | sed -n "$FT_LINE1","$FT_LINE2"p | rev | sort -r | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./' | tr -d '\n'
