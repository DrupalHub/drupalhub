<?php


class DrupalHubRestfulNode extends \DrupalHubEntityBase {

  /**
   * Get the path of the element. i.e: question => question.html#30.
   *
   * @param $nid
   *   The nid of the node.
   * @return string
   *   The path of the entry.
   */
  protected function generatePath($nid) {
    switch ($this->getBundle()) {
      case 'blog':
        return 'blog.html/#' . $nid;
    }
  }
}