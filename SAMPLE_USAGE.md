# Sample Usage

# Medicines Order
1. First you have to start a dialog with one of the following phrases:
```
__Hello__!
Let`s __start__!
I __want__ to __order__ some medicines.
```
2. Next you have to send a medicine in this format:
```
{medicine} {amount} (i.e.): Medicine Name 10
```
3. Next you have to confirm your enter with one of the following keywords:
```
Yes, Yep, Yeah, Sure
```
4. When you finish, you have to send one of the next phrases:
```
I have __done__.
__Enough__.
__Finished__. 
```
5. Bot will send you a formatted string with a result
6. Next you have to thank your bot for help
```
__Thank__ you!
```

# Gues Your Diasease
1. First you have to start a dialog with one of the following phrases:
```
__Hello__!
Let`s __start__!
I`ve got __sick__...
```
2. Next you have to send a symptom:
Please take a look at [db-bootstrap-data/009-mixed-diaseases-symptoms.sql](db-bootstrap-data/009-mixed-diaseases-symptoms.sql) for supported symptoms
3. When you finish, you have to send one of the next phrases:
```
I have __done__.
__Enough__.
__Finished__. 
```
4. Bot will send you a formatted string with a result
5. Next you have to thank your bot for help
```
__Thank__ you!
```

# Live Consultaion with Doctor
This module emulates ELIZA old progrm, so do not expect smart AI.

But Doctor can construct a simple dialog like this:
```
Hello!
How do you do. Please state your problem.
My name is Stoian.
Ok, such a good name, Stoian!
I want to buy an apple.
Why do you want buy an apple?
I want this girl.
Suppose you got this girl soon.
I am not sure...
Why not?
I am not agree with that!
Are you saying NO just to be negative?
I was so depressed last night...
Why do you tell me you were so depressed now?
I feel like a shit!
Do you often feel like a shit?
Good bye, doctor!
Ok, see you next time.
```

# NOTE!

Be __patient__ and __do not__ expect very cool AI!


