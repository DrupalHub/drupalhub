DrupalHub.config(function(uiGmapGoogleMapApiProvider, $translateProvider, language) {
  uiGmapGoogleMapApiProvider.configure({
    v: '3.17',
    libraries: 'weather,geometry,visualization'
  });

  $translateProvider.useStaticFilesLoader({
    prefix: 'languages/',
    suffix: '.json'
  });
  $translateProvider.preferredLanguage(language.code);
});
