"============================================================"
" Ride Sharing System - Smalltalk / Pharo 13"
" Demonstrates Encapsulation, Inheritance, and Polymorphism"
"============================================================"


"-------------------- Ride --------------------"

Object << #Ride
    slots: { #rideID. #pickupLocation. #dropoffLocation. #distance };
    package: 'RideSharingSystem'.

Ride >> initializeWithID: anID pickup: aPickup dropoff: aDropoff distance: aDistance
    rideID := anID.
    pickupLocation := aPickup.
    dropoffLocation := aDropoff.
    distance := aDistance.
    ^ self

Ride >> rideID
    ^ rideID

Ride >> pickupLocation
    ^ pickupLocation

Ride >> dropoffLocation
    ^ dropoffLocation

Ride >> distance
    ^ distance

Ride >> fare
    ^ distance * 2.0

Ride >> rideType
    ^ 'Ride'

Ride >> rideDetails
    Transcript
        show: 'Ride ID: ', rideID; cr;
        show: 'Type: ', self rideType; cr;
        show: 'Pickup: ', pickupLocation; cr;
        show: 'Drop-off: ', dropoffLocation; cr;
        show: 'Distance: ', distance printString, ' miles'; cr;
        show: 'Fare: $', self fare printString; cr


"-------------------- StandardRide --------------------"

Ride << #StandardRide
    slots: {};
    package: 'RideSharingSystem'.

StandardRide >> fare
    ^ self distance * 2.0

StandardRide >> rideType
    ^ 'Standard'


"-------------------- PremiumRide --------------------"

Ride << #PremiumRide
    slots: {};
    package: 'RideSharingSystem'.

PremiumRide >> fare
    ^ self distance * 3.5

PremiumRide >> rideType
    ^ 'Premium'


"-------------------- SharedRide --------------------"

Ride << #SharedRide
    slots: {};
    package: 'RideSharingSystem'.

SharedRide >> fare
    ^ self distance * 1.5

SharedRide >> rideType
    ^ 'Shared'


"-------------------- Driver --------------------"

Object << #Driver
    slots: { #driverID. #name. #rating. #assignedRides };
    package: 'RideSharingSystem'.

Driver >> initializeWithID: anID name: aName rating: aRating
    driverID := anID.
    name := aName.
    rating := aRating.
    assignedRides := OrderedCollection new.
    ^ self

Driver >> addRide: aRide
    assignedRides add: aRide

Driver >> getDriverInfo
    Transcript
        show: 'Driver ID: ', driverID; cr;
        show: 'Name: ', name; cr;
        show: 'Rating: ', rating printString; cr

Driver >> viewAssignedRides
    Transcript show: 'Completed Rides:'; cr.
    assignedRides do: [ :ride |
        Transcript
            show: ride rideID;
            show: ' - ';
            show: ride rideType;
            show: ' - $';
            show: ride fare printString;
            cr
    ]


"-------------------- Rider --------------------"

Object << #Rider
    slots: { #riderID. #name. #requestedRides };
    package: 'RideSharingSystem'.

Rider >> initializeWithID: anID name: aName
    riderID := anID.
    name := aName.
    requestedRides := OrderedCollection new.
    ^ self

Rider >> requestRide: aRide
    requestedRides add: aRide

Rider >> getRiderInfo
    Transcript
        show: 'Rider ID: ', riderID; cr;
        show: 'Name: ', name; cr

Rider >> viewRides
    Transcript show: 'Ride History:'; cr.
    requestedRides do: [ :ride |
        Transcript
            show: ride rideID;
            show: ' - ';
            show: ride rideType;
            show: ' - $';
            show: ride fare printString;
            cr
    ]


"============================================================"
" Demo"
"============================================================"

| standardRide premiumRide sharedRide rides driver rider |

Transcript clear.

Transcript
    show: '===================================='; cr;
    show: '       RIDE SHARING SYSTEM'; cr;
    show: '===================================='; cr; cr.

standardRide := StandardRide new
    initializeWithID: 'R101'
    pickup: 'Downtown Atlanta'
    dropoff: 'Midtown Atlanta'
    distance: 5.0.

premiumRide := PremiumRide new
    initializeWithID: 'R102'
    pickup: 'Midtown Atlanta'
    dropoff: 'Buckhead'
    distance: 8.0.

sharedRide := SharedRide new
    initializeWithID: 'R103'
    pickup: 'Buckhead'
    dropoff: 'Downtown Atlanta'
    distance: 10.0.

rides := {
    standardRide.
    premiumRide.
    sharedRide
}.

Transcript
    show: 'RIDE DETAILS'; cr;
    show: '------------------------------------'; cr.

rides do: [ :ride |
    ride rideDetails.
    Transcript show: '------------------------------------'; cr
].

Transcript
    cr;
    show: 'POLYMORPHIC FARE CALCULATION'; cr;
    show: '------------------------------------'; cr.

rides do: [ :ride |
    Transcript
        show: ride rideType;
        show: ' Ride (';
        show: ride distance printString;
        show: ' miles) -> $';
        show: ride fare printString;
        cr
].

driver := Driver new
    initializeWithID: 'D101'
    name: 'Alex'
    rating: 4.9.

driver addRide: standardRide.
driver addRide: premiumRide.

Transcript
    cr; cr;
    show: 'DRIVER INFORMATION'; cr;
    show: '------------------------------------'; cr.

driver getDriverInfo.
driver viewAssignedRides.

rider := Rider new
    initializeWithID: 'U101'
    name: 'Jahnavi'.

rider requestRide: standardRide.
rider requestRide: sharedRide.

Transcript
    cr; cr;
    show: 'RIDER INFORMATION'; cr;
    show: '------------------------------------'; cr.

rider getRiderInfo.
rider viewRides.

Transcript
    cr;
    show: '===================================='; cr;
    show: '          END OF DEMO'; cr;
    show: '===================================='; cr.