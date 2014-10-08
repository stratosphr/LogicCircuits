Logic
=====

Logic Circuit Simulation

+--------------------------------------------------------------------------------------------------+
+---------------------------------------------- TODO ----------------------------------------------+
+--------------------------------------------------------------------------------------------------+

Gate:
    -> Inherits Thread, Drawable
    -> run() method loops forever and checks whether any ancestor notified
    -> Stores ancestors
    -> Stores successors
    -> Only updates when notified by at least one ancestor
    -> Notifies all successors when updated AND state changed
    -> Superclass for TRUE, FALSE, CLOCK, NOT, AND, OR, XOR, NAND, NOR, XNOR preimplemented

/!\ libLogicGates
/!\ lib2D

+--------------------------------------------------------------------------------------------------+
+---------------------------------------------- COOL ----------------------------------------------+
+--------------------------------------------------------------------------------------------------+
NAND-LATCH
NOR-LATCH
D-LATCH
HALF-ADDER
FULL-ADDER
FULL-ADDER
COUNTER
MUX
DEMUX
CUSTOM GATE
Language
+--------------------------------------------------------------------------------------------------+
