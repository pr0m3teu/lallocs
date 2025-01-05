# Lallocs
This single-header library acts as a wrapper for 'malloc', 'free' and 'realloc'. Its functionality is storing each allocated pointer so that it can 
be kept track of and easily freed at the end of the program. It does this by using a linked-list and adding a new node to it with each allocation.
