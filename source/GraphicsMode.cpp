#include <stdio.h>
#include <math.h>
#include "raylib.h"

#include "../header/GraphicsIO.h"

enum ScreemParameters
{
    SCREEN_WIDTH = 1000, ///< Screen width
    SCREEN_LENGHT = 800 ///< Screen lenght
};
const float WIDTH_LIMIT = 1000000.0f; ///< Width limit of calculating area
const float HEIGHT_LIMIT = 1000000.0f; ///< Height limit of calculating area

/// Equation struct with float variables
struct EquationGraph
{
float a;
float b;
float c;
};


float GetY( EquationGraph* Equ, float x )
{
    return ( x * x * (Equ->a) + x * (Equ->b) + Equ->c );
}

bool EqualsFloat( float a, float b )
{
 return ( fabs( a-b ) <= 1e-5 ) ? true : false;
}

/// Distance between painted points
const float PAINT_STEP = 0.1f;

void PrintGraphic( EquationGraph* Equ )
{
    Equ->a = -Equ->a;
    Equ->b = -Equ->b;
    Equ->c = -Equ->c;

    InitWindow( SCREEN_WIDTH, SCREEN_LENGHT, "Function graph" );

    Vector2 CenterPosition = { SCREEN_WIDTH / 2, SCREEN_LENGHT / 2 };

    while( !WindowShouldClose() )
    {
        if ( IsKeyDown( KEY_RIGHT ) ) CenterPosition.x -= 2.0f;
        if ( IsKeyDown(  KEY_LEFT ) ) CenterPosition.x += 2.0f;
        if ( IsKeyDown(    KEY_UP ) ) CenterPosition.y += 2.0f;
        if ( IsKeyDown(  KEY_DOWN ) ) CenterPosition.y -= 2.0f;

        BeginDrawing();

        ClearBackground( BLACK );
        struct Vector2 RightPoint = { 0, GetY( Equ, 0 ) }, LeftPoint = { 0, GetY( Equ, 0 ) };
        struct Vector2 Leftprev = LeftPoint, Rightprev = RightPoint;
        float xDiff = 0;
        float yDiff = 0;
        while ( RightPoint.x <= WIDTH_LIMIT && RightPoint.y <= HEIGHT_LIMIT )
        {
            DrawLineV( RightPoint, Rightprev, BLUE );
            DrawLineV(  LeftPoint,  Leftprev, BLUE );
            Leftprev = LeftPoint;
            Rightprev = RightPoint;
            LeftPoint.x = LeftPoint.x - PAINT_STEP;
            RightPoint.x = RightPoint.x + PAINT_STEP;
            LeftPoint.y  = GetY( Equ,  LeftPoint.x - CenterPosition.x ) + CenterPosition.y;
            RightPoint.y = GetY( Equ, RightPoint.x - CenterPosition.x ) + CenterPosition.y;
        }

        if ( !EqualsFloat( Equ->a, 0 ) )
        {
            xDiff = -Equ->b / ( 2 * Equ->a );
            yDiff = ( Equ->c - Equ->b * Equ->b / ( 4 * Equ->a ) );
        }
        else if ( !EqualsFloat( Equ->b, 0 ) )
        {
            xDiff = Equ->c;
            yDiff = -Equ->c / Equ->b;
        }
        else
            xDiff = -Equ->c;
        DrawLineV( { CenterPosition.x - xDiff, HEIGHT_LIMIT }, { CenterPosition.x - xDiff, -HEIGHT_LIMIT }, WHITE );
        DrawLineV( { WIDTH_LIMIT, CenterPosition.y - yDiff }, { -WIDTH_LIMIT, CenterPosition.y - yDiff }, WHITE );

        EndDrawing();

    }

    CloseWindow();

}

void RunGraphicsMode()
{
    struct EquationGraph Equ = {};

    printf( " NB!!! To see graph, after running this code, print ./out into terminal\n" );
    GraphInput( &Equ );

}
