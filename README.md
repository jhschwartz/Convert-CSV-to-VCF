# Convert-CSV-to-VCF
Takes a csv of people, makes an easy VCF for your phone.

Requirements:
- command line
- C++
- A compiler, like g++

You must use a CSV in the following format:
- No titles
- Columns in this order: FIRST_NAME | LAST_NAME | CELL | EMAIL | COMPANY/ORGANIZATION

How to (Terminal):
1. clone this: `$ git clone https://github.com/jhschwartz/Convert-CSV-to-VCF`
2. put your .csv file in the same directory as the code
3. enter the directory: `$ cd Convert-CSV-to-VCF`
4. compile it: `$ g++ main.cpp converter`
5. run it: `$ ./conveter`
6. follow the prompts
7. You now have a vcf file. On a mac? Open it and it will import into Contacts. You can also email the .vcf to your iPhone and open it there. I don't know anything about Android sorry.

Thank you to [Loki Astari](https://stackoverflow.com/users/14065/loki-astari) who made this 100x easier and saved me a ton of time with [this stackoverflow answer](https://stackoverflow.com/a/1120224)
