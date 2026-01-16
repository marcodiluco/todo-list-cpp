#include "Date.h"
#include "Activity.h"
#include <cassert>
#include <iostream>

void testActivityConstructor() {
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
