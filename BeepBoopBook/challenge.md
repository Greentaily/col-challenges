wamb0t.10/10/2020

@everyone hey hey people, it's points earning time! I've listed two challenges below that you can try and complete in whatever language you see fit You have until 17/10 23:59 CET To submit your answers using the tag #BeepBoopBook. To submit, you can either:
- Spoiler your entire code and send it here (might be a bit buggy, so i'd recommend not doing this)
- Send a link to your code (through a website like repl.it or pastebin)
- DM Me your code

## Beginner Challenge (50 points)
You are tasked with making a function, that returns the amount of page flips it takes to get to a certain page in a book.

Important to note: When you open the book: The first page is on the right hand side, like so:

https://s3.amazonaws.com/hr-challenge-images/0/1481920803-d2b54f38f0-book.png

If I flip this page, I can see page 2 and 3. If I flip another page, I see page 4 and 5, etc etc.

Given n as the amount of pages in the book, and p as the page you need to turn to, return the minimal amount of pages you need to flip in order to reach page p.

Examples:

input: n = 5, p = 3
output: 1

input: n = 10, p = 1
output: 0

input: n = 400, p = 15
output: 7



## Intermediate challenge (50 points)

As you might have noticed in the beginner challenge, n is not used at all. This changes in the intermediate challenge! Now, **a student can start from both the beginning of the book, and the back!** Apart from that, the question stays the same.

Examples:

input: n = 5, p = 3
output: 1

input: n = 10, p = 1
output: 0

input: n = 6, p = 6
output: 0

input: n = 6, p = 5
output: 1

input: n = 10, p = 6
output: 2
