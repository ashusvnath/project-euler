(for i in `seq 1901 2000`; do cal $i | grep -A1 ^Su | cut -c 1-2,23-24,45-46 | grep "^ " | tr -d '\n '; done) | wc -c
