## C Coding Style Conventions

Code element | Convention | Example
--- | :---: | ---
Defines | SCREAM_SNAKE_CASE | `#define PLATFORM_DESKTOP`
Macros(DO NOT USE PLEASE) | SCREAM_SNAKE_CASE | `#define MIN(a,b) (((a)<(b))?(a):(b))`
Variables | camelCase | `int screenWidth = 0;`, `float targetFrameTime = 0.016f;`
Local variables | camelCase | `Vector2 playerPosition = { 0 };`
Global variables | camelCase | `bool phoneScreen = false;`
Constants | SCREAM_SNAKE_CASE | `const int MAX_VALUE = 8;`
Pointers | MyType *pointer | `Texture2D *array = NULL;`
float values | always x.xf | `float gravity = 10.0f`
Operators | value1 * value2 | `int product = value * 6;`
Operators | value1 / value2 | `int division = value / 4;`
Operators | value1 + value2 | `int sum = value + 10;`
Operators | value1 - value2 | `int res = value - 5;`
Enum | TitleCase | `enum PixelFormat`
Enum members | SCREAM_SNAKE_CASE | `PIXELFORMAT_UNCOMPRESSED_R8G8B8`
Struct | TitleCase | `struct Texture2D`, `struct Material`
Struct typedef | TitleCase | `typedef struct Texture { ... } Texture;`
Struct members | camelCase | `texture.widthPixels`
Functions | TitleCase | `InitWindow()`, `LoadImageFromMemory()`
Functions params | camelCase | `widthPixels`, `heightPixels`
Ternary Operator | (condition) ? result1 : result2 | `printf("Value is 0: %s", (value == 0) ? "yes" : "no");`

Other conventions:
 - All defined variables are ALWAYS initialized
 - Use .clang-format
 - Never ever waste a line with opening curly brace `{`
 - I am generally `snake_case` fan for C but due to raylib being used, I had to make some changes, pay attention to some `TitleCase` and `camelCase` rules.