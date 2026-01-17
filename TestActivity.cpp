#include "Date.h"
#include "Activity.h"
#include <cassert>
#include <iostream>

void TestActivityConstructor() {
    Date d;
    d.SetDay(15);
    d.SetMonth(3);
    d.SetYear(2026);
    Activity a("Studiare", d);

    // Controlla descrizione
    assert(a.GetDescription() == "Studiare");
    // Controlla data
    assert(a.GetDate().GetDay() == 15);
    assert(a.GetDate().GetMonth() == 3);
    assert(a.GetDate().GetYear() == 2026);
    // Controlla stato iniziale
    assert(a.IsComplete() == false);
}
void TestComplete() {
    Date d;
    Activity a("studiare", d);

    a.SetComplete();
    assert(a.IsComplete() == true);
    a.SetUnComplete();
    assert(a.IsComplete() == false);
}
void testSetDescription() {
    Date d;
    Activity a("Vecchia descrizione", d);

    a.SetDescription("Nuova descrizione");
    assert(a.GetDescription() == "Nuova descrizione");
}
void TestSetDate() {
    Date d1;
    d1.SetDay(1);
    d1.SetMonth(1);
    d1.SetYear(2026);
    Activity a("Comprare pane", d1);

    Date d2;
    d2.SetDay(20);
    d2.SetMonth(12);
    d2.SetYear(2026);
    a.SetDate(d2);

    assert(a.GetDate().GetDay() == 20);
    assert(a.GetDate().GetMonth() == 12);
    assert(a.GetDate().GetYear() == 2026);
}