Hirer:
    - name
    - email


Users: User[]
    User {
        id: str(UUID) - PK
        name
        email
        password
        bookings: Booking[]
        owned_venues: Venue[]
    }


Bookings: Booking[]
    Booking {
        id: str,
        hirer_id: user.id FK,
        venue_id: venue.id FK,
        event_name: str,
        guests: int,
        date_time: DateTime,
        duration_hrs: int
    }
