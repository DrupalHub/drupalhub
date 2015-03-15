<?php

/**
 * Class DrupalHubGoogleMapsApiGet
 *
 * This class will help us get the information of the address from Google maps
 * API using the lat and the long.
 */
class DrupalHubGoogleMapsApi {

  /**
   * @var integer
   *
   * The latitude.
   */
  protected $lat;

  /**
   * @var integer
   *
   * The longitude.
   */
  protected $long;

  /**
   * @var string
   *
   * The language to return the address. Based on Google Maps API,
   */
  protected $language;


  /**
   * @var string
   *
   * Store the JSON from Google API.
   */
  protected $json;

  /**
   * @param $lat
   *   The latitude.
   * @param $long
   *   longitude
   * @param string $language
   *   The language to return the address
   */
  function __construct($lat, $long, $language = 'he') {
    $this
      ->setLanguage($language)
      ->setLat($lat)
      ->setLong($long);
  }

  /**
   * @return string
   */
  public function getLanguage() {
    return $this->language;
  }

  /**
   * @param string $language
   *   The language of the address.
   *
   * @return $this
   *   The current object.
   */
  public function setLanguage($language) {
    $this->language = $language;
    return $this;
  }

  /**
   * @return int
   */
  public function getLat() {
    return $this->lat;
  }

  /**
   * @param int $lat
   *   The latitude of the address.
   *
   * @return $this
   *   The current object.
   */
  public function setLat($lat) {
    $this->lat = $lat;
    return $this;
  }

  /**
   * @return int
   */
  public function getLong() {
    return $this->long;
  }

  /**
   * @param int $long
   *
   * @return $this
   *   The current object.
   */
  public function setLong($long) {
    $this->long = $long;
    return $this;
  }

  /**
   * @param $key
   *   Get a specific name. Optional.
   *
   * @return array
   *   Return the results from Google API or a specific address.
   */
  public function GetAddress($key = NULL) {
    $url = 'http://maps.googleapis.com/maps/api/geocode/json?latlng=' .
      $this->getLat() . ',' .
      $this->getLong() .
      '&sensor=false&language=' . $this->getLanguage();

    $data = @file_get_contents($url);
    $json = json_decode($data,true);

    if ($json['status'] != 'OK') {
      return array();
    }

    $this->json = $json['results'][0];

    $results = array(
      'country' => $this->getGoogleCountry(),
      'province' => $this->getGoogleProvince(),
      'city' => $this->getGoogleCity(),
      'street' => $this->getGoogleStreet(),
      'postal_code' => $this->getGooglePostalCode(),
      'country_code' => $this->getGoogleCountryCode(),
      'formatted_address' => $this->getGoogleAddress(),
    );

    if ($key) {
      return $results[$key];
    }

    return $results;
  }

  /**
   * Get the country.
   */
  protected function getGoogleCountry() {
    return $this->FindLongNameGivenType('country', $this->json['address_components']);
  }

  /**
   * Get the province.
   */
  protected function getGoogleProvince() {
    return $this->FindLongNameGivenType('administrative_area_level_1', $this->json['address_components'], TRUE);
  }

  /**
   * Get the city.
   */
  protected function getGoogleCity() {
    return $this->FindLongNameGivenType('locality', $this->json['address_components']);
  }

  /**
   * Get the street.
   */
  protected function getGoogleStreet() {
    return $this->FindLongNameGivenType('street_number', $this->json['address_components']) . ' ' . $this->FindLongNameGivenType('route', $this->json['address_components']);
  }

  /**
   * Get postal code.
   */
  protected function getGooglePostalCode() {
    return $this->FindLongNameGivenType('postal_code', $this->json['address_components']);
  }

  /**
   * Get the country code.
   */
  protected function getGoogleCountryCode() {
    return $this->FindLongNameGivenType('country', $this->json['address_components'], TRUE);
  }

  /**
   * Get a formatted address.
   */
  protected function getGoogleAddress() {
    return $this->json['formatted_address'];
  }

  /**
   * Get the long name from a given type.
   */
  protected function FindLongNameGivenType($type, $array, $short_name = FALSE) {
    foreach( $array as $value) {
      if (in_array($type, $value['types'])) {
        if ($short_name){
          return $value['short_name'];
        }
        return $value['long_name'];
      }
    }
  }
}

