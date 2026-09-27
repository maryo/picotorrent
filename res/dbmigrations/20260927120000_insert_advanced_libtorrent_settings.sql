INSERT INTO setting (key, value, default_value)
VALUES
    ('libtorrent.announce_ip', NULL, '""'),
    ('libtorrent.rate_limit_ip_overhead', NULL, 'true'),
    ('libtorrent.enable_outgoing_utp', NULL, 'true'),
    ('libtorrent.enable_incoming_utp', NULL, 'true'),
    ('libtorrent.enable_outgoing_tcp', NULL, 'true'),
    ('libtorrent.enable_incoming_tcp', NULL, 'true'),
    ('libtorrent.dht_privacy_lookups', NULL, 'false');
