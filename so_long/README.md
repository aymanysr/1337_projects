<h1>so_long</h1>

A simple 2D tile‐based game using MLX42 where you collect all items and reach the exit.
Map files are in maps, assets in textures, and source code in src (with bonus features in bonus).

<h1>Features</h1>
<ul>
  <li>
  Custom map parsing and validation.
  </li>
  <li>
  Real-time rendering using MLX42.
  </li>
  <li>
  Player control and basic enemy movement.
  </li>
  <li>
  Modular code structure with dedicated modules for textures, assets, and rendering.
  </li>
  <li>
  Integrated ft_printf library for formatted output.
  </li>
  <li>
  Comprehensive error handling and resource cleanup.
  </li>
</ul>

<h1>Getting Started</h1>
<h2>
  Prerequisites
</h2>
<ul>
  <li>
    C Compiler (compatible with C99 or later)
  </li>
  <li>
    Make
  </li>
  <li>
    cmake
  </li>
  <li>
    GLFW and OpenGL dependencies (handled in MLX42 build)
  </li>  
<ul>
  <h2>
    Installation and Build
  </h2>
<ol>
  <li>
    Clone the repository:
    <br>
        git clone https://github.com/aymanysr/1337_projects.git
  </li>
  <li>
    Build MLX42 (located in the lib/MLX42 directory) and then compile the so_long project:
    <br>
        make
  </li>
</ol>

A sample Makefile is provided in the repository. Refer to the Basics documentation for additional makefile configurations.

<h1>
  Project Structure
</h1>
<h2>
  The repository is organized as follows:
</h2>

-- <bold>**/includes**</bold> – Header files for the game logic.

-- <bold>**/src**</bold> – Source code for game functionalities including map handling, rendering, and controls.

-- <bold>**/lib/MLX42**</bold> – MLX42 library, responsible for window handling and graphics rendering.
      Documentation in /lib/MLX42/docs
      XPM42 image format details in XPM42.md
      
-- <bold>**/ft_printf**</bold> – Custom implementation of ft_printf for formatted output.
      Documentation in ft_printf/README.md
      
-- <bold>**.github**</bold> – Issue templates and community files.

-- <bold>**.gitignore**</bold> – Specifies build artifacts and other ignored files

<h1> 🛠️ Build & Run </h1>
<ol>
  <li>
    Clone and build MLX42:
  </li>
    
  -- make mlx42
  
  <li>
    Build utility libs and the game:
  </li>

  -- make
  
  <li>
    Run with a map:
  </li>
  
  -- ./so_long maps/<map>.ber

  <li>Clean objects and binaries:</li>

  -- fclean
</ol>
  

<h1>🎮 Gameplay</h1>

<ul>
  <li>Move: ← ↑ ↓ → or A W S D</li>
    
  <li>Objective: Collect all C then reach E</li>
  
  <li>Walls (1) are impassable.</li>
  
  <li>Bonus: Enemies (M) patrol horizontally—contact ends game.</li>
</ul>

<h1>🗺️ Map Format</h1>
<h5>Rectangular grid of characters:</h5>
<ul>
    <li>1 wall</li>
    <li>0 empty floor</li>
    <li>P player start (exactly one)</li>
    <li>C collectible (≥ 1)</li>
    <li>E exit (exactly one)</li>
    <li>M enemy (bonus)</li>
</ul>
<h5>Fully enclosed by walls.</h5>

<h1>🔧 Core Flow</h1>

=> game = malloc(sizeof(t_game));

=> vars_initializer(game);

=> vars_initializer_bonus(game);

=> parse + validate map via components_checker;     // [`components_checker`](src/map_validation.c)

=> mlx_initializer(game);                           // [`mlx_initializer`](src/assets_loader.c)

=> game_banner();                                   // [`game_banner`](src/banner.c)

=> load_enemy_textures(game);                       // [`load_enemy_textures`](bonus/textures_bonus.c)

=> init_enemies(game);                              // [`init_enemies`](bonus/enemy_init_bonus.c)

=> initialize_game(game);                           // [`initialize_game`](src/assets_loader.c)

=> mlx_key_hook(…, player_controller, game);        // [`player_controller`](src/player_control.c)

=> mlx_loop_hook(…, update_game, game);             // [`update_game`](src/update_game.c)

=> mlx_loop(mlx_ptr);                               // MLX42 main loop

=> cleanup_game(game);                              // [`cleanup_game`](src/cleanup.c)


<h1>🧹 Cleanup</h1>

<h5>All MLX42 resources, textures, images, maps and enemy arrays are freed in cleanup_game.</h5>

<h5>Enjoy traversing your map! 🕹️</h5>

