# Solutions for Lab 2 Activity

**Neel Amrutia**  
**February 7, 2025**  

## Contents
1. [Part 1: grep Tasks](#part-1-grep-tasks)
2. [Part 2: awk Tasks](#part-2-awk-tasks)
3. [Part 3: sed Tasks](#part-3-sed-tasks)

---

## Part 1: grep Tasks

### 1. Exact Word Search
Find all lines in `sample.txt` containing the exact word `pattern`.
```bash
grep -w "pattern" sample.txt
```

### 2. Limit Matching Lines
Display the first 3 lines containing the word `log`.
```bash
grep "log" sample.txt | head -n 3
```

### 3. Pattern File Matching
Search for lines matching patterns from `patterns.txt`.
```bash
grep -f patterns.txt sample.txt
```

### 4. Count Non-Matching Lines
Count lines not containing `debug`.
```bash
grep -v "debug" sample.txt | wc -l
```

### 5. Search for Dates
Find lines containing dates in `YYYY-MM-DD` format.
```bash
grep -E "[0-9]{4}-[0-9]{2}-[0-9]{2}" sample.txt
```

---

## Part 2: awk Tasks

### 1. Filter Lines Based on Condition
Print lines where the second field is greater than `50`.
```bash
awk -F ',' '$2 > 50' data.csv
```

### 2. Add to Field Values
Add `10` to the first field of all lines.
```bash
awk -F ',' -v OFS=',' '{ $1 = $1 + 10; print }' data.csv
```

### 3. Find Duplicate Lines
Identify duplicate lines.
```bash
awk '!seen[$0]++ { next } { print }' data.csv
```

### 4. Maximum of Average Values
Compute the maximum of column averages.
```bash
awk -F ',' '{
    sum1 += $1; sum2 += $2; sum3 += $3;
    count++;
}
END {
    avg1 = sum1 / count;
    avg2 = sum2 / count;
    avg3 = sum3 / count;
    max = (avg1 > avg2 ? avg1 : avg2);
    max = (max > avg3 ? max : avg3);
    print max;
}' data.csv
```

---

## Part 3: sed Tasks

### 1. Delete Specific Lines
Remove lines `3 to 5`.
```bash
sed '3,5d' sample.txt
```

### 2. Replace Word in File
Replace `important` with `lite`.
```bash
sed 's/important/lite/g' sample.txt
```

### 3. Transform Characters
Convert lowercase to uppercase.
```bash
sed 's/[a-z]/\U&/g' sample.txt > temp.txt
```
OR 

```bash
tr 'a-z' 'A-Z' < sample.txt
```

### 4. Multiple Substitutions
Replace `code` with `coding` and `summary` with `iss`.
```bash
sed -e 's/code/coding/g' -e 's/summary/iss/g' sample.txt
```

### 5. Extract Specific Lines
Save lines `10 to 20` to a new file.
```bash
sed -n '10,20p' sample.txt > output.txt
```

### 6. Reverse Line Order
Reverse the line order.
```bash
sed '1!G;h;$!d' sample.txt