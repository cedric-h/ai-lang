
# The ai programming language

**ai** (comes from japanese 「愛」 "love", read like "eye") is a small cross-platform compiled scripting programming language for 64-bit processors with custom optimizing backend. The goal is to provide the low-level access to memory and operating system subroutines, while at the same time provide the user with high-level abstractions.

The language is currently in the prototyping and early development stage.

Small syntax draft:

```
#!/usr/bin/ai
# For comments. Which is why hashbangs work naturally

#*
  Block comments (#**#) can be typed without left hand leaving `shift` key.
  Block comments nest.
*#

# Variable declarations
let x        = 1.3;
let x: Float = 1.3;

# If statement's conditions do not require
#  parenthesis around the expression
if x > 1 {

  # assert operator.
  assert 2==3 and 7<x or 2+1==3;

  # print operator.
  print x;
}

# For statement for now is the only looping mechanism
let i = 0;
for i < 10 {
  print i;
  i += 1;
}

# For i in [array] is a very nice syntax that can be used
# to loop through some particular values.
for i in [0..10] {

}

# `for let` is the third construction that can 
#   be combined with the two above
#   This construction introduces body-scoped variable
#   with the lifetime equal to execution of the loop
for let i = 0; i < 10 {
  i += 1;
}
```


