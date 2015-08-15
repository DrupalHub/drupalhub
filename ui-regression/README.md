## Providers

For local testing use phantomJs ``phantomjs --webdriver=4444``

Otherwise you can use BrowserStack or Sauce Labs:

```bash
# Set BrowserStack keys
export BROWSERSTACK_USERNAME=<username>
export BROWSERSTACK_KEY=<token>
```

OR

```bash
# Set Suace Labs keys
export SAUCE_USERNAME=<username>
export SAUCE_ACCESS_KEY=<token>
```

# Usage

``mocha`` will tests all the files under the ``test`` folder.

The example file shows how a single test file can be executed under multiple platforms and browsers. Assuming we are using browserstack, this can be executed by passing the environment argument like this:

```bash
# Execute the tests using the ie11 config.
PROVIDER_PREFIX=browserstack SELECTED_CAPS=ie11 mocha

# Execute the tests using the chrome on Mac config.
PROVIDER_PREFIX=browserstack SELECTED_CAPS=chrome mocha

# Execute the tests with the default capabilities provided by the `shoov-webdrivercss` library.
mocha
```

After a regression was found check your [Builds](http://shoov.gizra.com/#/builds) page, or go directly to the link indicated by the failing Mocha test.

# Credits

[Gizra](http://gizra.com)
