Introduction
In this project, we'll code a simple 2D game to get familiar with the mlx library and UI in general. In my case, it will be Pac-Man.

Game Rules
The game we choose must follow a set of rules. The executable so_long will receive a map as the only argument, and this map will have a .ber filetype.

The file also must follow these rules:

Only P (pacman), 1 (wall), 0 (empty), C (collectible), and E (exit) will be accepted characters in our map (except if you add enemies as bonus)
The map must be rectangular, i.e. all rows must have the same length
There must be at least one exit, one player, and one collectible on the map
The map must be closed, i.e. surrounded by walls
If any of these checks fail, the game must end with Error\n followed by a custom message.

The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

How it Works
For the graphics part of the project we used a library called minilibx. It's fairly basic and somewhat limited, but was still fun to use in the project.

Part 1: reading the map
In this part of the code I checked that the given map was properly opened, that it had a .ber filetype, and then continued by reading the file one line at a time with get_next_line. Once that was done I filled a struct t_lay with some basic map attributes like number of players, exits, collectibles, number of rows and columns, etc. During the reading process I also created a string containing the entire map, whcih was later useful when creating a matrix with ft_split with \n as the separator.

Part 2: starting the game
For this part I took the t_lay and my map matrix to build my main t_game struct. This struct includes more detailed information about my game state, such a list of pacmans, a list of ghosts, the number of loop repetitions (frames), and other info. From here I initialized a window with the mlx function and started drawing the static elements of the map (walls, spaces and collectibles) on the window. The mlx library, as other graphic libraries, has an infinite loop where the game events happen. From here I check the state of the game to re-print certain elements of the map or to manage special events, such as when Pacman dies or when ghosts are in panic mode. The mlx library has hooks, which essentially link certain events on the computer (keypresses, mouse clicks, etc) with functions we implement. In my case I 'hooked' the end of the game function to pressing the x button to close the window. Also, I used a key hook to link keypresses with pacman's movements.

Part 3: game mechanics
