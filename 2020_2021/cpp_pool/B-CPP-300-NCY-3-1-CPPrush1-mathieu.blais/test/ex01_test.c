/*
** EPITECH PROJECT, 2021
** test_rush
** File description:
** ex01
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../object.h"
#include "../player.h"
#include "../raise.h"
#include "../new.h"
#include "../vertex.h"
#include "../point.h"

cr_redirect_stdout()

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(rush, test_suject_exo3, .init=redirect_all_stdout)
{
    printf("\n=======[test_new_vertex_int]=======\n");

    cr_assert_stdout_eq_str("<Point (12 , 13)> + <Point (2, 2)> = <Point (14, 15)> \
    <Point (12 , 13)> - <Point (2, 2)> = <Point (10, 11)> \
    <Vertex (1, 2, 3)> + <Vertex (4, 5, 6)> = <Vertex (5, 7, 9)> \
    <Vertex (1, 2, 3)> - <Vertex (4, 5, 6)> = <Vertex (-3, -3, -3)>");

    Object * p1 = new (Point, 12, 13);
    Object * p2 = new (Point, 2, 2);
    printf("%s+%s=%s\n", str(p1), str(p2), str(addition(p1, p2)));
    printf("%s-%s=%s\n", str(p1), str(p2), str(subtraction(p1, p2)));
    Object * v1 = new(Vertex, 1, 2, 3);
    Object * v2 = new(Vertex, 4, 5, 6);
    printf("%s+%s=%s\n", str(v1), str(v2), str(addition(v1, v2)));
    printf("%s-%s=%s\n", str(v1), str(v2), str(subtraction(v1, v2)));

    printf("\n");
}

Test(rush, test_new_vertex_int)
{
    printf("\n=======[test_new_vertex_int]=======\n");
    
    Object *player = new(Player);
    cr_assert(new(Vertex, 2147483646, -12131423, 4367826487234) != NULL);
    delete(player);

    printf("\n");
}

Test(rush, test_new_vertex_string)
{
    printf("\n=======[test_new_vertex_string]=======\n");

    Object *player = new(Player);
    cr_assert(new(Vertex, "kejwrefnad", "3jwrgefansdm", "krjwbefnsd") != NULL);
    delete(player);

    printf("\n");
}

Test(rush, test_new_vertex)
{
    printf("\n=======[test_new_vertex]=======\n");

    Object *player = new(Player);
    cr_assert(new(Vertex, 0, 1, 2) != NULL);
    delete(player);
}

Test(rush, test_new_point)
{
    printf("\n=======[test_new_point]=======\n");

    Object *player = new(Player);
    cr_assert(new(Point , 42 , -42) != NULL);
    delete(player);
}

Test(rush, test_delete)
{
    printf("\n=======[test_delete]=======\n");

    Object *player = new (Player);
    delete(player);
    cr_assert(player == NULL);
} 