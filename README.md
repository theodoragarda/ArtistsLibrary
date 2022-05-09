## ArtistsLibrary

Implemented functions:

- [x] Getters & setters for all attributes of every class
- [x] Add
- [x] Remove by ID
- [x] Display all artists
- [x] Filter artists by their type (display only khh or krnb artists)
- [x] Display all artists which have the streams lower than a given value
- [x] Persistence
- [x] Undo
- [x] Redo
 

## _Classes:_
- **Artist** (_base class_): 
    - _ID_ (m_id): the ID of the artist (unique for each artist)
    - _streams_ (m_streams): the streams of an artist


- **KHH** (_derived from Artist_): Aside from the ID and streams inherited from the class Artist, a KHH object has as attributes: 
    - *number of albums* (m_nrAlbums): how many albmus such an artist has
    - _company_ (m_company): the comapny of the artist
    - _name_ (m_name): the name of the artist


- **KRnB** (_derived from Artist_): Aside from the ID and streams inherited from the class Artist, a KHH object has as attributes: 
    - *number of albums* (m_nrAlbums): how many albmus such an artist has
    - _company_ (m_company): the comapny of the artist
    - _name_ (m_name): the name of the artist


- **ArtistRepository**: The collection of artist of all types


- **ArtistController**


- **UserInterface**
