#include <iostream>
#include "_Movie.cpp"
#include "_Seat.cpp"
#include "_Screen.cpp"
#include "_Cinema.cpp"
#include "_Show.cpp"
#include "_ShowSeat.cpp"
#include "_Customer.cpp"
#include "_Booking.cpp"
#include  "_Payment.cpp"
#include "_PaymentTypes.cpp"
#include "_PriceCalculator.cpp"
#include "_TicketPrinter.cpp"
#include "_BookingService.cpp"
#include "_Snack.cpp"
using namespace std;

int main() {
    Cinema cinema("PVR Pacific Mall");
    Screen audi1(1, "Audi-01 (IMAX)");
    audi1.addSeat(Seat("A1", SeatTier::PLATINUM));
    audi1.addSeat(Seat("A2", SeatTier::PLATINUM));
    audi1.addSeat(Seat("B1", SeatTier::GOLD));
    cinema.addScreen(audi1);

    Movie movie("Oppenheimer", "English", 180);
    Show eveningShow(101, "07:00 PM", &movie, &cinema.getScreens()[0]);

    BookingService service(&cinema);
    service.addShow(&eveningShow);

    // Tumhara Nam aur Detail:
    Customer customer("Yash Diwakar", "+91-9876543210");

    cout << "\n======================================================\n";
    cout << "           CINEMA TICKETING SYSTEM DEMO RUN           \n";
    cout << "======================================================\n";

    eveningShow.displaySeatLayout();

    cout << "\n>>> [DEMO USE CASE] Booking seat A1 via UPI...\n";
    UpiPayment upiSuccess("yash@okaxis", true);
    Booking* b1 = service.bookSeat(0, &customer, "A1", &upiSuccess);

    cout << "\n>>> [EDGE CASE 1] Attempting to book already BOOKED seat A1...\n";
    UpiPayment upiRetry("other@upi", true);
    service.bookSeat(0, &customer, "A1", &upiRetry);

    cout << "\n>>> [EDGE CASE 2] Attempting to book seat A2 with failing payment...\n";
    UpiPayment upiFailing("yash@badupi", false);
    service.bookSeat(0, &customer, "A2", &upiFailing);
    eveningShow.displaySeatLayout();

    if (b1 != nullptr) {
        cout << "\n>>> [EDGE CASE 3] Cancelling booking " << b1->getBookingId() << "...\n";
        service.cancelBooking(b1->getBookingId());
        eveningShow.displaySeatLayout();
    }

    cout << "\n>>> [EDGE CASE 4a] Selecting non-existent seat Z99...\n";
    service.bookSeat(0, &customer, "Z99", &upiSuccess);

    cout << "\n>>> [EDGE CASE 4b] Selecting invalid show index 5...\n";
    service.bookSeat(5, &customer, "A1", &upiSuccess);

    cout << "\nDemo completed safely with 0 crashes.\n";
    return 0;
}