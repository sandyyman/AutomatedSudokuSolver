The goal of the Automated Sudoku Solver project in C is to create a smart program that can
solve Sudoku puzzles without human input. Sudoku puzzles involve placing numbers in a grid,
and our program uses the C programming language to automatically figure out the right
numbers for each puzzle. To solve Sudoku puzzles, our program uses a technique called
backtracking, which helps it explore different solutions, make smart choices, and go back when
needed. The project involves a two-fold process: parsing input Sudoku puzzles from a file, and
implementing the solving algorithm. Users can input Sudoku puzzles by providing a file as
input, and the solver produces both console output for immediate feedback and a new file
containing the solved puzzle. User interaction is prioritized in this project, with an emphasis
on flexibility. Users can input Sudoku puzzles through files, each containing puzzles of different
difficulty levels. The solver produces console output for immediate feedback and generates new
files containing the solved puzzles.

Functions:
Function to validate puzzle: The integrity of the Sudoku puzzle is maintained through a
validation function. This critical component checks the current state of the puzzle against
the rules of Sudoku, ensuring that each row, column, and 3x3 subgrid remains free of
duplicate digits. Its role is pivotal in confirming the correctness of the solver's progress.
Function to solve the puzzle: At the heart of the project lies a sophisticated backtracking
algorithm. This function systematically fills empty cells in the grid while constantly
validating the puzzle's adherence to rules. If a conflict arises at any point, the algorithm
gracefully backtracks to explore alternative solutions, embodying the essence of efficient
puzzle-solving

Function to print the puzzle: Enhancing the user experience, this function provides a
visual representation of the Sudoku grid at various stages of solving. Users can observe
the evolving state of the puzzle, gaining insights into the solver's decision-making
process.

Function to read the puzzle: The project accommodates a variety of Sudoku puzzles by
allowing users to input puzzles from external text files. This function reads puzzle
configurations from specified files, facilitating the testing of different scenarios and
promoting versatility.

Choice to choose difficulty level: Users can tailor their experience based on difficulty
levels using a switch-case structure. This intuitive interface enables users to select a
difficulty level (easy, medium, or hard). The corresponding puzzle file is then loaded for
solving, allowing users to customize their Sudoku-solving challenges.
