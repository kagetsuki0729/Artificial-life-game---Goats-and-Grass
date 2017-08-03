# Artificial-life-game---Goats-and-Grass
<p>
Homework from Object-oriented Programming in NCCU
</p>
<hr>
<h2>Usage</h2>
<p>
Type <code>make</code> to compile<br>
Type <code>./ALifeTest_ [passes] [display] [seed]</code> to excute<br>
</p>
<h2>Document</h2>
<div class=WordSection1>
<p class=MsoNormal style='margin-bottom:6.0pt;text-align:justify;text-justify:
inter-ideograph;line-height:normal;text-autospace:none;vertical-align:bottom'><b><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'>Topic:</span></b><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'> Design
a simulator for an artificial life game with goats and grass.</span></p>

<p class=MsoNormal style='margin-bottom:6.0pt;text-align:justify;text-justify:
inter-ideograph;line-height:normal;text-autospace:none;vertical-align:bottom'><b><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'>Objective:</span></b><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'> Practice
polymorphism in class inheritance.</span></p>

<p class=MsoNormal style='margin-bottom:6.0pt;text-align:justify;text-justify:
inter-ideograph;line-height:normal;text-autospace:none;vertical-align:bottom'><b><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'>Description:
</span></b></p>

<p class=BodyText2 style='margin-bottom:6.0pt;text-autospace:none;vertical-align:
bottom'><span lang=EN-US style='font-family:"Times New Roman","serif"'>In this
assignment, you will design a simulation of predatory and prey relationship
where goats are predators and grass is the prey. Goats appear in the console
window of fixed size as X’s and grass as I’s. (Examples are shown in the
following section.) The “world” consists of a 35x20 array. All creatures live
in cells of this array. The world does not wrap around, i.e., there are firm
boundaries at the edges of the array. Initially there are 5 goats and 10 blades
of grass scattered randomly. As time processes, each creature in the world
takes its turn to act for living. The complete set of turns by all living
creatures is called a <i>pass</i>. During each pass, goats move around and eat
grass while the grass grows.&nbsp; </span></p>

<p class=BodyText2 style='margin-bottom:6.0pt;text-autospace:none;vertical-align:
bottom'><span lang=EN-US style='font-family:"Times New Roman","serif"'>During a
pass, each goat is allowed to move in a randomly selected direction, provided
the square is not currently occupied by another goat or outside the boundaries
of the world. When the attempt is not <i>legal</i>, the goat does not get
another chance to try again. That is, a goat has only one chance to move in
each pass. When a goat moves to a new cell, it gets to eat any grass on the
cell. Each goat starts with 20 food points and consumes 1 point with each pass.
Every time the goat eats a blade of grass it gains 5 points.</span></p>

<p class=BodyText2 style='margin-bottom:6.0pt;text-autospace:none;vertical-align:
bottom'><span lang=EN-US style='font-family:"Times New Roman","serif"'>Goats
also age (become older). When a goat is born, it is zero days old. It then
grows one day older with each pass until it dies (disappear) at the age of 70
days. However, between the ages of 50 and 55 inclusively, a goat can have a
baby goat for each pass. To do so, the mommy goat picks a random direction and
generates a baby goat one cell away in that direction, provided that the cell
is legal. If the square contains a blade of grass, the mommy goat also gets to
eat the grass and acquires the usual food points. However, the mommy goat does
not move during this process. There are no daddy goats and we won’t worry about
how the goats get pregnant. Goats die if their food points reach zero or their
lives are over 70 days. </span></p>

<p class=BodyText2 style='margin-bottom:6.0pt;text-autospace:none;vertical-align:
bottom'><span lang=EN-US style='font-family:"Times New Roman","serif"'>The
behavior of grass is simpler. Grass never moves and doesn’t eat. Grass starts
out with an age of zero and grows one day older with each pass. When a blade of
grass reaches 6 days, it dies (disappears). Grass can sprout new grass between
the age of 3 and 5 inclusively. Like goats, a mommy grass picks a random
direction and generates a baby grass at that neighboring cell if it is empty. If
it fails, it does not do another attempt.&nbsp; </span></p>

<p class=BodyText2 style='margin-bottom:6.0pt;text-autospace:none;vertical-align:
bottom'><span lang=EN-US style='font-family:"Times New Roman","serif"'>During
each pass of the simulation, the program scan the world row by row from left to
right and call upon each creature found to act. You have to make sure that each
creature only acts once in each pass even if it has moved. For example, a goat
may move to a new cell that will be scanned in a later time. In this case, you
must have a way of jumping over that goat. In addition, baby goats and baby
grass do not act during their first day of existence; they are merely
by-products of existing creatures. </span></p>

<p class=BodyText2 style='margin-bottom:6.0pt;text-autospace:none;vertical-align:
bottom'><span lang=EN-US style='font-family:"Times New Roman","serif"'>A sample
interface is shown as below. I suggest you to play with the sample executable
first to get a feel of what it does. The user can specify three optional parameters
from the command line. The first parameter is the number of passes to run. The
second parameter is the number of passes between every display of the world.
The third parameter is the seed for the random number generator. For example, </span><span
lang=EN-US style='font-family:"Courier New"'>AlifeTest_sun4 1000 100 1234</span><span
lang=EN-US style='font-family:"Times New Roman","serif"'> means that the
simulation will run for 1000 passes and display the world once every 100 passes
with the seed of 1234 for the random number generator. If the user specifies
zero passes, or a negative number, the program defaults to a single pass. </span></p>

<p class=MsoNormal style='margin-bottom:6.0pt;text-align:justify;text-justify:
inter-ideograph;line-height:normal;text-autospace:none;vertical-align:bottom'><b><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'>Sample
Output: </span></b></p>
<pre>
li@ghost 2:35pm [74] ALife>ALifeTest_i86pc 10001 10000
  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
0                                             X
1
2                                     X
3                     I
4
5
6                                               X
7                 X                                       I
8                                                 I
9                                     I     X
0
1
2                 I                                     I
3
4             I                                     I
5
6
7
8
9                       I                                 I
------------------------------------------------------------------------ 
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
0       X   X     I I I I                                 X       I   I
1       X           I                                       X I I I
2           X     X I I I I                               X   X     X
3           I   I   I   I                 X       X       I I       I I
4       X   I   I I I X   I I I                         X I I     I I I
5       X       I I                     X     X I I   I X   I   I     I
6           I I I I I I I   I X         X           I I     I I I   I I
7       I   I   X   I             X X   X         I I       I       I I
8       I   I   I I I I I       I I I I   I             I I   X
9 X         X I I I I I I X I I I   I   I I X     I   X X     X       X
0       I     I I I I I I I I X     I         X I I       I     X
1     I I         I       I     I I I   X     X I X   I
2 I I   I I   I       X I I   I I I I       I I I       X           X
3 I I I I     I                 I         I   I X         X       X
4 I   I X I   I                 X I       I I I   X
5 I I I         I I                   X       I I   X
6 I           X   I       X I I I I I     X   I I I I
7 X X   I I   X X I         I I I I I   X                   X
8     I     I I I I X         I   I I I                 X
9     I       X               X I       I   I   X               X     X
</pre>

<p class=MsoNormal style='margin-top:6.0pt;margin-right:0cm;margin-bottom:6.0pt;
margin-left:0cm;text-align:justify;text-justify:inter-ideograph;line-height:
normal;text-autospace:none;vertical-align:bottom'><b><span lang=EN-US
style='font-size:11.0pt;font-family:"Times New Roman","serif"'>Implementation
Notes:</span></b></p>

<p class=BodyText2 style='margin-bottom:6.0pt;text-autospace:none;vertical-align:
bottom'><span lang=EN-US style='font-family:"Times New Roman","serif"'>The
design of this program is largely up to you; however, the random number
generator class (</span><span lang=EN-US style='font-family:"Courier New"'>RandomNum.h</span><span
lang=EN-US style='font-family:"Times New Roman","serif"'> and </span><span
lang=EN-US style='font-family:"Courier New"'>RandomNum.cc</span><span
lang=EN-US style='font-family:"Times New Roman","serif"'>) and the main testing
function (</span><span lang=EN-US style='font-family:"Courier New"'>ALifeTest.cc</span><span
lang=EN-US style='font-family:"Times New Roman","serif"'>) is given to you. You
are encouraged to design your class member carefully such that a member tries
to be as </span><span lang=EN-US style='font-family:"Courier New"'>private</span><span
lang=EN-US style='font-family:"Times New Roman","serif"'>, </span><span
lang=EN-US style='font-family:"Courier New"'>protected</span><span lang=EN-US
style='font-family:"Times New Roman","serif"'>, and then </span><span
lang=EN-US style='font-family:"Courier New"'>public</span><span lang=EN-US
style='font-family:"Times New Roman","serif"'> in this order. We expect all
derivations to follow the IS-A rule. In addition, remember that the purpose of
this assignment is to practice polymorphism (e.g. virtual function) in class
inheritance. Therefore, how good you have designed this part of class will be an
important criterion in grading your program. </span></p>

<p class=MsoNormal style='margin-bottom:6.0pt;text-align:justify;text-justify:
inter-ideograph;line-height:normal;text-autospace:none;vertical-align:bottom'><b><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'>What
to Hand in:</span></b></p>

<p class=MsoNormal style='margin-bottom:6.0pt;text-align:justify;text-justify:
inter-ideograph;line-height:normal;text-autospace:none;vertical-align:bottom'><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'>As
usually, you need to submit a complete program electronically. For hardcopies,
you only need to submit the files that are written by you. In this assignment,
you do not have to print out the </span><span lang=EN-US style='font-size:11.0pt;
font-family:"Courier New"'>RandomNum</span><span lang=EN-US style='font-size:
11.0pt;font-family:"Times New Roman","serif"'> class and the </span><span
lang=EN-US style='font-size:11.0pt;font-family:"Courier New"'>ALifeTest.cc </span><span
lang=EN-US style='font-size:11.0pt;font-family:"Times New Roman","serif"'>file
unless you have made significant changes to these files.</span></p>

</div>
