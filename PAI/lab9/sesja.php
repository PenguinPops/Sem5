<?php
session_start();
echo 'ID: ' . session_id() . '<br />';
if (!isset($_SESSION['our_own'])) {
    session_regenerate_id();
    $_SESSION['our_own'] = true;
}
