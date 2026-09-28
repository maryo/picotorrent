/* The updater plugin used to point at the original upstream author's own
   api.picotorrent.org endpoint, which reports the original project's
   releases, not this fork's. Point it at this fork's own GitHub releases
   API instead - the response shape differs (tag_name/html_url instead of
   version/url), which the updater plugin itself was updated to handle.

   This is not a user-exposed preference (no UI sets it), but "value" can
   still be non-NULL here - eg. RestoreDefaults() copies every setting's
   default_value into value, which would otherwise freeze this one on the
   old URL even after default_value is updated above. Overwrite both. */
UPDATE setting
SET value = '"https://api.github.com/repos/maryo/picotorrent/releases/latest"',
    default_value = '"https://api.github.com/repos/maryo/picotorrent/releases/latest"'
WHERE key = 'update_checks.url';
